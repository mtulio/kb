# AWS-CLI


## S3

* Upload 'single-part' object

```
aws s3api put-object --bucket ${BUCKET_NAME} \
  --key "${OBJECT_NAME} --body ${LOCAL_FILE}
```

* Upload object with ACL

> TODO

## Route53

* Authorize DNS resolution between VPC in different accounts

> TODO
