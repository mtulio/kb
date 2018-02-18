# Frequently Asqued Questions

This is FAQ from Quizes and courses

* [Core Concepts](#core-concepts)


## Core Concepts

**1) The connection between the apiserver and nodes, pods and services:**

*Choose the correct answer:*

* Is unencrypted and therefore unsafe to run over public networks.
* Is always encrypted with IPSec.
* Is currently encrypted with IPSec with plans to allow other encryption plugins later.
* Is always encrypted using the method configured in the .kube file.

**2) Unique IP addresses are assigned to:**

*Choose the correct answer:*

* NAT is used extensively, so unique IP addresses are irrelevant
* Pods
* Container Hosts
* Containers

**3) What does a pod represent in a Kubernetes cluster?**

*Choose the correct answer:*

* A running process
* A set of rules for maintaining high availability
* Conditions under which applications will autoscale
* All the containers in the cluster

**4) Which of these are not inherently created by Kubernetes?**

*Choose the correct answer:*

* Controllers
* Services
* Pods
* Nodes


**5) What controls a Kubernetes cluster?**

*Correct answer*

* The Master
* The Pod
* The Node
* The swarm

**6)Containers are run on which of these?**

*Choose the correct answer:*

* Nodes
* None of these
* Controllers
* Services


**7) Communications between the apiserver and the kubelet on the cluster nodes are used for all but which of the following?**

*Choose the correct answer:*

* Keep-alive xml packets
* Fetching logs for pods
* Attaching (through kubectl) to running pods
* Providing the kubelet's port-forwarding capability

**8) Kubernetes changed the name of cluster members to "Nodes." What were they called before that?**

*Choose the correct answer:*

* Slaves
* Cogs
* Workers
* Minions

**9) In a typical deployment, the Kubernetes Master listens on what port number?**

*Choose the correct answer:*

* 443
* 3001
* 80
* 22

**10) Which of these is a list of common Kubernetes primitives?**

*Choose the correct answer:*

* containers, vms, hypervisors, daemons
* pod, swarm, namespace, network
* service, deployment, replicaset, etcd
* pod, service, persistentVolume, deployment

**11) Usually, when submitting a Kubernetes API call, data is sent in which format? (Select all that apply)**

*Choose the 2 correct answers:*

 - [ ] DOC
 - [ ] JSON
 - [ ] XML
 - [ ] YAML

**12) In Kubernetes, a group of one or more containers is called:**

*Choose the correct answer:*

* A pod
* A selector
* A minion
* A swarm

**13) Which of these components mount volumes to containers?**

*Choose the correct answer:*

* fluentd
* kube-scheduler
* kube-proxy
* kubelet

**14) If memory is running low on a running node, which of these keys will return "True"?**

*Choose the correct answer:*

* MemoryPressure
* Warning
* LowMemory
* OOM

**15) What is the difference between a Docker volume and a Kubernetes volume?**

*Choose the correct answer:*

* Proximity: In Docker, volumes can reside on the same host with their containers. In Kubernetes, they must reside on separate metal for resiliency.
* Back-end Drivers. Docker supports more block storage types than Kubernetes does.
* Volume lifetimes. In Docker, this is loosely defined. In Kubernetes, the volume has the same lifetime as its surrounding pod.
* Size: Docker volumes are limited to 3TB. Kubernetes volumes are limited to 16TB.

___

### Answers

**1) The connection between the apiserver and nodes, pods and services:**

*Correct answer*
Is unencrypted and therefore unsafe to run over public networks.

*Explanation*
It's a fairly simple process to encrypt the streams using TLS.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**2) Unique IP addresses are assigned to:**

*Correct answer*
Pods

*Explanation*
A pod gets assigned a single IP address, regardless of how many containers make it up. This is analogous to many services running on a single virtual machine.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**3) What does a pod represent in a Kubernetes cluster?**

*Correct answer*
A running process

*Explanation*
Pods are the running containers in a Kubernetes cluster.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**4) Which of these are not inherently created by Kubernetes?**

*Correct answer*
Nodes

*Explanation*
Nodes are added to a cluster, and a Kubernetes object is created to reflect them, but Kubernetes itself doesn't create them.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**5) What controls a Kubernetes cluster?**

*Correct answer*
The Master

*Explanation*
The master node contains the Kubernetes api server, which controls what the cluster does.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**6) Containers are run on which of these?*

*Correct answer*
Nodes

*Explanation*
Nodes run the pods.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**7) Communications between the apiserver and the kubelet on the cluster nodes are used for all but which of the following?**

*Correct answer*
Keep-alive xml packets

*Explanation*
Communications between the apiServer and the Kubelet are constantly communicating for a variety of purposes.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**8) Kubernetes changed the name of cluster members to "Nodes." What were they called before that?**

*Correct answer*
Minions

*Explanation*
A lot of documentation and tutorials online still refer to worker nodes this way.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**9) In a typical deployment, the Kubernetes Master listens on what port number?**

*Correct answer*
443

*Explanation*
The API server, by default, listens on port 443, the secure HTTP port.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**10) Which of these is a list of common Kubernetes primitives?**

*Correct answer*
pod, service, persistentVolume, deployment

*Explanation*
There are many others, but those are the ones you'll likely work with most often.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**11) Usually, when submitting a Kubernetes API call, data is sent in which format? (Select all that apply)**

*Correct answer*
JSON, YAML

*Explanation*
If using a direct API call in an application, JSON is used. If using kubectl to submit a request, it takes YAML.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**12) In Kubernetes, a group of one or more containers is called:**

*Correct answer*
A pod

*Explanation*
A pod is usually one container but can be a group of containers working together.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**13) Which of these components mount volumes to containers?**

*Correct answer*
kubelet

*Explanation*
The kubelet which runs on nodes handles moment-to-moment management of the pods on its node.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**14) If memory is running low on a running node, which of these keys will return "True"?**

*Correct answer*
MemoryPressure

*Explanation*
MemoryPressure and DiskPressure return true as a node starts to become overcommitted.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155

**15) What is the difference between a Docker volume and a Kubernetes volume?**

*Correct answer*
Volume lifetimes. In Docker, this is loosely defined. In Kubernetes, the volume has the same lifetime as its surrounding pod.

*Explanation*
Docker volumes are not used in conjunction with Kubernetes at this time.

*Further Reading*
https://linuxacademy.com/cp/courses/lesson/course/1412/lesson/1/module/155
