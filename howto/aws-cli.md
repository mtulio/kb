# AWS-CLI


## S3

* Upload 'single-part' object

```
aws s3api put-object --bucket ${BUCKET_NAME} \
  --key "${OBJECT_NAME} --body ${LOCAL_FILE}
```
