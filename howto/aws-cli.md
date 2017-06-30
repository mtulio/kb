# AWS-CLI


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
