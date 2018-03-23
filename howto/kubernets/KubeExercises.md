# K8s Exercises

___

Exercises from courses

* Run a Job
* Deploy a Pod
* Create the service
* Explore the Sandbox
* Deployments - Rollout
* Setting Container Environment Variables

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


## Deployments - Rollout

* **Description**

Here is some yaml for an nginx deployment:

```yaml
apiVersion: apps/v1beta2
kind: Deployment
metadata:
  name: nginx-deployment
spec:
  selector:
    matchLabels:
      app: nginx
  replicas: 2 
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:1.7.9
        ports:
        - containerPort: 80
```

1. Create the deployment.
2. Which nodes are the pods running on. How can you tell?
3. Update the deployment to use the 1.8 version of the nginx container and roll it out.
4. Update the deployment to use the 1.9.1 version of the nginx container and roll it out.
5. Roll back the deployment to the 1.8 version of the container.
6. Remove the deployment

* **Answer**

1. Create the yaml file and name it something. I chose `nginx-deployment.yaml`. Create the deployment object by calling `kubectl create -f nginx-deployment.yaml`.
2. You can find this answer by doing a `kubectl describe deployment nginx-deployment`.
3. There are many ways to get this:
* `kubectl get pods -l app=nginx -o wide` gives you the results in one step and uses a label selector.
Or, you could:
* `kubectl describe deployment nginx-deployment` to get the pod information about the deployment and, using that,
`kubectl get pods name-of-pods -o wide`

4. There are many ways. Here are two:
* `kubectl set image deployment nginx-deployment nginx=nginx:1.8`. This will work just fine but is not the preferred method because now the yaml is inconsistent with what you've got running in the cluster. Anyone coming across your yaml will assume it's what is up and running and it isn't.
* Update the line in the yaml to the 1.8 version of the image, and apply the changes with `kubectl apply -f nginx-deployment.yaml`
5. Same as above. Don't forget you can watch the status of the rollout with the command `kubectl rollout status deployment nginx-deployment`.

6. `kubectl rollout undo deployment nginx-deployment` will undo the previous rollout, or if you want to go to a specific point in history, you can view the history with `kubectl rollout history deployment nginx-deployment` and roll back to a specific state with `kubectl rollout history deployment nginx-deployment --revision=x`.

## Setting Container Environment Variables

* **Description**

1. Write yaml for a job that will run the busybox image and will print out its environment variables and shut down.
2. Add the following environment variables to the pod definition:
```
STUDENT_NAME="Your Name"
SCHOOL="Linux Academy"
KUBERNETES="is awesome"
```
3. Run the job.
4. Verify that the environment variables were added.

* **Answer**

1. There are lots of possibilities, but here is what I came up with:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: env-dump
spec:
  containers:
  - name: busybox
    image: busybox
    command:
      - env
```
2. Change the yaml to something like this:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: env-dump
spec:
  containers:
  - name: busybox
    image: busybox
    command:
      - env
    env:
    - name: STUDENT_NAME
      value: "Your Name"
    - name: SCHOOL
      value: "Linux Academy"
    - name: KUBERNETES
      value: "is awesome"
```
3. kubectl create -f env-dump.yaml and wait for the pod to return the status of "Completed."
4. kubectl logs env-dump will show all the environment variables.
