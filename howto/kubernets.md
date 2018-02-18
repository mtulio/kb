# kubernets


## Installing

### CentOS

In this hands-on, we'll go through everything you need to install Kubernetes on a bare CentOS system:

1) Disable the Swap on the system

* Disable the swap

```bash
sudo swapoff -a

cp /etc/fstab /etc/fstab.bkp
grep -e swap /etc/fstab.bkp > /etc/fstab
```

* Update the system

```bash
yum update
```

* Setup docker

```bash
yum -y install docker
systemctl enable docker
systemctl start docker
```

* Turning off Selinux when installing and permissive after the boot

```bash
setenforce 0
```

```bash
vim /etc/selinux/config
SELINUX=permmissive
```

* Setup kubernets repo

```bash
cat < /etc/yum.repos.d/kubernetes.repo
[kubernetes]
name=Kubernetes
baseurl=https://packages.cloud.google.com/yum/repos/kubernetes-el7-x86_64
enabled=1
gpgcheck=1
repo_gpgcheck=1
gpgkey=https://packages.cloud.google.com/yum/doc/yum-key.gpg https://packages.cloud.google.com/yum/doc/rpm-package-key.gpg
EOF
```

* Install, enable and start Kubernet

```bash
yum install -y kubelet kubeadm kubectl
systemctl enable kubelet
systemctl start kubelet
```

* Allow service on bridge network

```bash
cat <  /etc/sysctl.d/k8s.conf
net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
EOF
```

sysctl --system

```bash
kubectl apply -f https://raw.githubusercontent.com/coreos/flannel/v0.9.1/Documentation/kube-flannel.yml
```

* [Setup cluster](#setup-cluster)


## Setup Cluster


1) On then master, setup init with it's Network

```bash
sudo kubeadm init --pod-network-cidr=10.244.0.0/16
```

2) On the Master, make the security adjustments on the config files

```bash
  mkdir -p $HOME/.kube
  sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
  sudo chown $(id -u):$(id -g) $HOME/.kube/config
```

3) On the Master, setup network mode - pull up kube services to networking of Pods

```bash
  sudo kubectl apply -f https://raw.githubusercontent.com/coreos/flannel/v0.9.1/Documentation/kube-flannel.yml
```

4) On the Slaves, add nodes to the cluster

```bash
  sudo kubeadm join --token 94d0c6.682d4365b4a89xxx 172.31.119.3:6443 --discovery-token-ca-cert-hash sha256:xxx5380eee01e7a9029d9b1cff6d20b49a5f7f20439fb19ed0b31475e8177xxx
```

x) See all pods from all namespaces

```bash
  kubectl get pods --all-namespaces
```

x) See all nodes

```bash
  kubectl get nodes
```
