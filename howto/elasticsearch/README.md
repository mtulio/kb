# HowTO Elasticsearch

## API Rest

### Get node cluster info

```shell
  curl http://${NODE_NAME}:9200/
```

### Get nodes 

```shell
  curl http://${NODE_NAME}:9200/_nodes
```

### Allocate shards to an node

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

* Refs and credits: 
  * https://www.elastic.co/guide/en/elasticsearch/reference/current/disk-allocator.html
  * https://www.datadoghq.com/blog/elasticsearch-unassigned-shards/
 

## PLUGINS

### Install kopf

> TODO
