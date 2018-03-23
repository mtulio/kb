# kubernets

Core annotations and handson based mainly on Kubernet courses.

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

### Standalone cluster (Minikube)

1. Install Minikube: 
`curl -Lo minikube https://storage.googleapis.com/minikube/releases/v0.25.0/minikube-linux-amd64 && chmod +x minikube && sudo mv minikube /usr/local/bin/`
1. Follow this guide: https://kubernetes.io/docs/getting-started-guides/minikube/
1. Setup with docker
`minikube start --vm-driver=none`
1. Run the app
`kubectl run hello-minikube --image=k8s.gcr.io/echoserver:1.4 --port=8080`
1. Create deployment
`kubectl expose deployment hello-minikube --type=NodePort`
1. Show URL for service
`kubectl get services hello-minikube`
1. Show URL for pod
`minikube service hello-minikube --url`
1. Enable the dashboard
`minikube dashboard`
1. delete service
` kubectl delete service hello-minikube`
1. delete deployments
`kubectl delete deployments hello-minikube`

## Concepts

### Common Objects

* Nodes
* Pods
* Deployments
* Services
* ConfigMaps

### Common names on Architecture

* Names
* UIDs
* Namespaces - Virtual clusters
* Nodes
* Cloud Controller manager
* Node Controller

### Services & Network Primitives

* Services
 * Containers are running in Pods
 * Pods are (usually) managed by deployments
 * Service expose deployments
 * Third parties handle load balancing  or port forwarding to those  services, though ingress objects (along with an appropriate ingress controller) are needed to do that work
 * Imperative - CLI
 * Declarative - YAML files
 
 
## Imperative CLI
 
### EXEC / RUN
 
 * `kubectl exec mynginx -i -y -- /bin/bash`
 
### Pods
 
 * `kubectl get pods`
 * `kubectl run mysample --image=latest123/apache`
 * `kubectl run myreplicas --image=latest123/apache --replicas=2 --labels=app=myapache,version`
 * `kubectl describe deployment myreplicas`
 * Describe by labels
 `kubectl get pods -l versions`
 
### Deployments
 
 * kubectl create -f deployment-nginx.yaml
```yaml
apiversion: v1
kind: Deployment
metadata: 
  name: nginx-deployment-dev
spec:
  replicas: 1
  template:
    metadata:
      labels:
        app: nginx-deployment-dev
    spec:
      containers:
        - name: nginx-deployment-dev
          image: nginx:1.7.9
          ports:
            - containerPort: 80
```
 * kubectl get deployments
 * kubectl describe deployments -l app=nginx-deployment-dev
 * kubectl apply -f nginx-deployment-yaml
 * kubectl get pods
 * kubectl get replicationControllers

### Rolling updates / and rollback

* Rolling out changing image version - Update the image nginx-deployment
```bash
kubectl set image deployment/nginx-deployment nginx=nginx:1.8
kubectl rollout status deployment/nginx-deployment
kubectl describe deployment nginx-deployment

```
* Rolling out changing the deployment YAML file - and rolling back
```bash
<CHANGE IMAGE VERSION in YAML file>
kubectl apply -f nginx-deployment.yaml
kubectl rollout status deployment/nginx-deployment
kubectl get deployments
<ROLLBACK>
kubectl rollout history deployment/nginx-deployment --revision=2
kubectl rollouy undo deployment/nginx-deployment --to-revision=2
<vim nginx-deployment.yaml>
kubectl apply -f nginx-deployment.yaml
kubectl rollout status deployment nginx-deployment
kubectl describe deployment nginx-deployment
```

### LOGS

```bash
 kubectl get pods
 kubectl logs myapache
 kubectl logs --tail=1 myapache
 kubectl logs --since=24h myapache
 kubectl logs -f myapache
 kubectl logs -f -c CID myapache
```

### Autoscaling and Scaling the Pods

* Steps to deploy nginx service
```bash
kubectl run myas --image=nginx --port=80 --labels=app=myautoscale
kubectl get deployments
kubectl autoscale deployment myas --min=2 --max=6
kubectl autoscale deployment myas --min=2 --max=6 --cpu-percent=10
kubectl get deployments
kubectl scale --current-replicas=2 --replicas=4 deployment/myas
kubectl get deployments
kubectl get pods
kubectl scale --current-replicas=4 --replicas=2 deployment/myas
kubectl get deployments
kubectl get pods
```

### Backup

```bash
kubectl get deployments nginx-deployment -o yaml
```

### Applications (Hands On)

* how kubernets configures applications
`kubectl create configmap my-map --from-literam=school=LinuxAcademy`

* Check the config map

`kubectl get configmaps`

* describe content

`kubectl configmaps my-map`

* describe content (getting YAML)

`kubectlt get configmap my-map -o yaml`

* Getting config
`cat pod-config.yaml`

* Create from yaml

```bash
kubectl create -f pod-config.yaml
kubectl get pods
kubectl logs config-test-pod
```

### Scaling Applications

* HandsOn command
```
kubectl get deployments
kubectl deribe deployment nginx-deployment
kubectl scale deployment/nginx-deployment --replicas=3
kubectl get deployments
kubectl get pods
kubectl scale deployment/nginx-deployment --replicas=1
kubectl get pods
kubectl scale deployment/nginx-deployment --replicas=2

```

## Scheduling

### Labels & Selectors

How can you identify a pod or other resource?  Labels!  In this hands-on lesson, we'll look at labeling everything and then how to find it again using selectors.

#### Sample labels

* "release": "stable", "release": "canary"
* "environment": "dev", "environment": "qa", "environment": "production"
* "tier": "frontend", "tier": "backend", "tier": "cache"
* "track": "daily", "track": "weekly"

* HandsOn commands

```bash
# get pods by labels
kubectl get pods
kubectl get pods -l app=nginx
kubectl get pods -l app=mysql

# label one pode
kubectl label pod mysql-53333-grtk test=sure --overwrite
kubectl describe pod -l test=sure

# label group of pods
kubectl label pods -l app=nginx tier=frontend

# remove resource by labels
kubectl delete pods -l test=sure
kubectl get pods

# show again resources, without deleted
kubectl describe pod -l test=sure
```

### DaemonSets

In this hands-on lesson, we'll take a closer look at a DaemonSet already running on your cluster and discuss their use cases.

* HandsOn Commands

```bash
kubectl get daemonsets -n kube-system #namespace kube-system

# get info about flannel CNI
kubectl describe daemonset kube-flannel-ds -n kube-system

```
### Resource Limits & Pod Scheduling

In this hands-on lesson, we'll discuss how to set limits and how pods get scheduled based on their needs.

* HandsOn Commands

```bash

kubectl get nodes

kubectl describe node myserver.mtulio.net

# Allow  to schedulle pods without tolerations
kubectl taint myserver.mtulio.net node-role.kubernets.io/master-

# Disallow to schedulle pods - back kto taint tollerations
kubectl taint node myserver.mtulio.net node-role.kubernets.io=master:NoSchedule

```

### Self-Healing Applications

In this hands-on lesson we'll show you how applications in Kubernetes are self-healing because of the way Kubernetes constantly monitors the cluster and compares it with the specifications.


* HandsOn Commands

```bash
kubectl get deployments
kubectl get pods
# delete the pods to check self healing - creating new one pod by k8s
kubectl delete pod nginx-deplooyment-53495345354-gzda31

# 
kubectl describe pod nginx-deployment

#> shutdown one node
# show nodes down
kubectl get nodes

kubectl get deployments
kubectl get pods

kubectl describe deployment nginx-deployment

kubect get pods

kubectl describe pod nginx-deploy-ments
#> Check tolerations

kubectl get pods

kubectl get deployments

kubectl get nodes


```


# Kops

* Deploy cluster

```bash
bash-3.2$ export NAME=example.nivenly.com
bash-3.2$ export KOPS_STATE_STORE=s3://nivenly-state-store
bash-3.2$ kops create cluster --zones us-west-2a $NAME 
```



# Exercises

* [All K8s exeercises](kubernets/KubeExercises.md)

# Quiz

* [All K8s quizes](kubernets/KubeQuiz.md)

