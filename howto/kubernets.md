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
 
### LOGS
 
 kubectl get pods
 kubectl logs myapache
 kubectl logs --tail=1 myapache
 kubectl logs --since=24h myapache
 kubectl logs -f myapache
 kubectl logs -f -c CID myapache
 
### Autoscaling and Scaling the Pods
 
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


# Exercises
 
## Run a Job
 
Applications that run to completion inside a pod are called "jobs."  This is useful for doing batch processing.

Most Kubernetes objects are created using yaml. Here is some sample yaml for a job which uses perl to calculate pi to 2000 digits and then stops.

```yaml
apiVersion: batch/v1
kind: Job
metadata:
  name: pi
spec:
  template:
    spec:
      containers:
      - name: pi
        image: perl
        command: ["perl",  "-Mbignum=bpi", "-wle", "print bpi(2000)"]
      restartPolicy: Never
  backoffLimit: 4
```

Create this yaml file on your master node and call it "pi-job.yaml". Run the job with the command:

```bash
kubectl create -f pi-job.yaml
```

1. Check the status of the job using the `kubectl describe jobs` command.
2. When the job is complete, view the results by using the `kubectl logs <JOB_NAME>` command on the appropriate pod.
3. Write yaml for a new job.  Use the image "busybox" and have it sleep for 10 seconds and then complete.  Run your job to be sure it works.

```yaml
apiVersion: batch/v1
kind: Job
metadata:
  name: sleep
spec:
  template:
    spec:
      containers:
      - name: sleep
        image: busybox
        command: ["sleep", "10"]
      restartPolicy: Never
  backoffLimit: 4
```
* Commands
```bash
kubectl create -f job-sleep.yml 
kubectl describe jobs
kubectl get pods
kubectl get pods --show-all
kubectl logs sleep-wht9w
kubectl describe jobs
kubectl delete jobs sleep
```

## Deploy a Pod

Pods usually represent running applications in a Kubernetes cluster.  Here is an example of some yaml which defines a pod:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: alpine
  namespace: default
spec:
  containers:
  - name: alpine
    image: alpine
    command:
      - sleep
      - "3600"
    imagePullPolicy: IfNotPresent
  restartPolicy: Always

```
1. Looking at the yaml, describe what the pod will do.
2. Run the pod.
3. Delete the pod.

```bash
kubectl create -f pod-alpine.yaml
kubectl get pods
kubectl desccribe pods
```

4. Write yaml for a pod that runs the nginx image.
5. Run your yaml to ensure it functions as expected.


```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-pod
spec:
  containers:
    - name: nginx
      image: nginx
  restartPolicy: Always
```

```bash
kubectl create -f nginx-pod.yaml
kubectl get pods
```

Delete any user pods you created during this exercise.

```bash
kubectl delete -f pod-alpine.yaml
kubectl delete pod nginx-prod
kubectl delete pod/nginx-prod
```

## Create the service

* Setup

```yaml
apiVersion: v1
kind: Service
metadata:
  name: nginx-service
  labels:
    app: nginx-service
spec:
  ports:
    - port: 8000
      targetPort: 80
      protocol: TCP
  selector:
    app: nginx

```


```bash
kubectl create -f service-nginx.yaml
```

* Check

```bash
kubectl get services
kubectl describe service nginx-service
```

* Test

```bash
kubectl run busybox --generator=run-pod/v1 --image=busybox --restart=Never --tty -i
wget -qO- http://10.111.20.191:8000
```


# Quiz

* [Core Concepts](kubernets/KubeFAQ.md)

