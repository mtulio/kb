# HowTO Elasticsearch

## CLI

### Reassign unhealth shards to an node

```shell
curl -XPOST -d '{ "commands" : [ {
  "allocate" : {
       "index" : "${INDEX_NAME}", 
       "shard" : ${SHARD_ID}, 
       "node" : "${NODE_NAME}-${CLUSTER_NAME}",
       "allow_primary":true 
     } 
  } ] }' http://${NODE_NAME}:9200/_cluster/reroute?pretty
```

Change/Where:
 - NODE_NAME
 - CLUSTER_NAME
 - SHARD_ID
 - INDEX_NAME


## PLUGINS

### Install kopf
