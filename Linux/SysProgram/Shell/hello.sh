#date
export NAME=chengzhi
readonly AGE=12+12
#AGE=111
echo $NAME $AGE
NUM=10
M=1
function find_you()
{
	local M=2
	echo $M
	echo "find you"
	echo $1 $2
	return 1
}

find_me()
{
	echo "find me"
}

find_me

find_you hello world
echo $?


FUN=`find_you hello world`
echo $FUN








exit
VAR=1
while [ $VAR2 -lt 10 ]
do
	echo $VAR2
	VAR2=$[ $VAR2 + 1 ]
done





exit
case $NAME in
"aronn")
	echo "arron"
	;;
"chengzhi")
	echo "chengzhi"
	;;
*)
	echo "chengzhi"
	;;
esac



exit

for VAR in 1 2 3
do
	echo $VAR
done




exit

#if test $NAME="chengzhi"
#if test -z $NAME
#if test $NUM -eq 10
#if [ $NUM -eq 10 ]
#if test -e hello2.sh
if [ -x hello2.sh ]
then
	echo "true"
else
	echo "false"
fi	




exit


read V1 V2 V3
echo $V1
echo $V2
echo $V3



exit
VALUE=$[$[12 + 12] + 10]
VALUE2=`expr $VALUE + 12 \* 12`
VALUE3=`expr $VALUE \* 12`
echo $VALUE
echo $VALUE2
echo $VALUE3

echo "print $"
echo "\$0 = $0"
echo "\$1 = $1"
echo "\$2 = $2"
echo "\$# = $#"
echo "\$@ = $@"
echo "\$* = $*"
echo "\$$ = $$"

echo "print env"
echo $HOME
echo $PATH
echo $PWD
echo $PS1
echo $PS2


















