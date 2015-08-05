#!/bin/bash

#
# Test of understanding/concept options at: http://www.gnu.org/software/bash/manual/bash.html#Shell-Parameter-Expansion
#
#########################################
# ${parameter:-word} : If parameter is unset or null, the expansion of word is substituted. Otherwise, the value of parameter is substituted. 
#
# ${parameter:=word} : If parameter is unset or null, the expansion of word is assigned to parameter. The value of parameter is then substituted. Positional parameters and special parameters may not be assigned to in this way.
#
# ${parameter:?word} : If parameter is null or unset, the expansion of word (or a message to that effect if word is not present) is written to the standard error and the shell, if it is not interactive, exits. Otherwise, the value of parameter is substituted.
#
# ${parameter:+word} : If parameter is null or unset, nothing is substituted, otherwise the expansion of word is substituted.
#
echo
echo "Assigned static value for VAR1"
VAR1=val1
echo "[VAR1=val1]=[${VAR1}]"

VAR2=${VAR1:-val2}
echo "[\${VAR1:-val2}]=[${VAR2}]"

VAR2=${VAR1:=val2}
echo "[\${VAR1:=val2}]=[${VAR2}]"

VAR2=${VAR1:?val2}
echo "[\${VAR1:?val2}]=[${VAR2}]"

VAR2=${VAR1:+val2}
echo "[\${VAR1:+val2}]=[${VAR2}]"

echo 
echo "Unsetting vars: VAR1 and VAR2..."
unset VAR1
unset VAR2

VAR2=${VAR1:-val2}
echo "[\${VAR1:-val2}]=[${VAR2}]"

VAR2=${VAR1:=val2}
echo "[\${VAR1:=val2}]=[${VAR2}]"

VAR2=${VAR1:?val2}
echo "[\${VAR1:?val2}]=[${VAR2}]"

VAR2=${VAR1:+val2}
echo "[\${VAR1:+val2}]=[${VAR2}]"

echo 
#########################################
