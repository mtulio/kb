# Bash Parameters Expansion 

## Testing options of Parameters Expansion

```
$ bash  bash parameter_expansion.sh 
Starting test of concept.

Assigned static value for VAR1
[VAR1=val1] :[val1]
[${VAR1:-val2}]=[val1]
[${VAR1:=val2}]=[val1]
[${VAR1:?val2}]=[val1]
[${VAR1:+val2}]=[val2]

Unsetting vars: VAR1 and VAR2...
[${VAR1:-val2}]=[val2]
[${VAR1:=val2}]=[val2]
[${VAR1:?val2}]=[val2]
[${VAR1:+val2}]=[val2]

```

Manual: 
 * http://www.gnu.org/software/bash/manual/bash.html#Shell-Parameter-Expansion
