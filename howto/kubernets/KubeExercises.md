# K8s Exercises

Exercises from courses

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



## Explore the Sandbox

* **Description**

1. Examine the current status of your cluster. Are all the nodes ready? How do you know?
2. Are there any pods running on node 2 of your cluster? How can you tell?
3. Is the master node low on memory currently? How can you tell?
4. What pods are running in the kube-system namespace? What command did you use to find out?

* **Answers**

1. The command kubectl get nodes will give the current status of all nodes.
2. You can get this information in a variety of ways:
* kubectl describe node node-name
* kubectl get pods --all-namespaces -o wide will list all pods and which nodes they are currently running on.
3. kubectl describe node node-2-name will list DiskPressure and MemoryPressure statuses so you can see how it is doing.
4. kubectl get pods -n kube-system will provide the desired results.


