# AWS-CLI

## EC2

* Basic filter instances by tag Name

`aws ec2 describe-instances --filters "Name=tag:Name,Values=cache-master*"`

* Basic Query by Tag Name returning only the `InstanceId`, `ImageId` and `tag Name`

```
aws ec2 describe-instances --filters "Name=tag:Name,Values=cache-master*" --query 'Reservations[*].Instances[*].[InstanceId,ImageId,Tags[?Key==`Name`].Value]'
```

* Modify termination protection for too instances

> This is not recommended, but for massive maintanence sometimes we need to do this. For your own risk =)
> Please have a look in `aws cli` documentation: https://docs.aws.amazon.com/cli/latest/reference/ec2/modify-instance-attribute.html

```
for i in $(aws ec2 describe-instances --filters "Name=tag:Name,Values=cache-bf2018*" --query 'Reservations[*].Instances[*].[InstanceId]'  |jq .[].[] |grep ^'"i-' |tr -d '"'); do \
  aws ec2 modify-instance-attribute --instance-id $i --disable-api-termination; \
done
```




## S3

* Upload 'multi-part' object

`aws s3 cp --region ${AWS_REGION} ${LOCAL_FILE} s3://{BUCKET_NAME}/${OBJECT_NAME}`

* Upload 'single-part' object

```
aws s3api put-object --bucket ${BUCKET_NAME} --key ${OBJECT_NAME} --body ${LOCAL_FILE}
```
>> The command won't display stdout, I didn't find any verbose option... have a seat and take a coffe =p

* Upload object with ACL

> TODO

## Route53

* Authorize DNS resolution between VPC in different accounts

> TODO
