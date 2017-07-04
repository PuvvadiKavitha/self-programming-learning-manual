# /bin/bash
date
A=1
find_me()
{
	local A=2
	echo "hello chengzhi"
	echo $1,$2
	return 1

}
find_me hello chengzhi
echo $?

exit

function find_you()
{
	echo "Hello World"

}

FUNC_RESULT=`find_you`
echo $FUNC_RESULT


exit
export NAME=chengzhi
AGE=24
# if [ -b helloworld.sh ]
# then
#    echo "true"
# else
#	echo "false"
#fi	
case $AGE in
20)
	echo "error"
	;;
24)
	echo "true"
	;;
*)
    echo "other"
	;;
esac	

for var in 1 2 3
do
	echo $var
	
done	


var1=2
until [ $var1 -lt 10 ]
do
	echo "print $var1"
	var1=$[$var1 + 1]
done	



exit

read VA1 VA2 VA3 
echo  $VA3
AGE=$[ AGE + 1 ]
AGE=$[$[ AGE + 2 ] + 1 ]

echo $NAME $AGE 
# print $
echo "\$0 = $0"
echo "\$1 = $1"
echo "\$# = $#"
echo "\$@ = $@"
echo "\$? = $?"
echo "\$* = $*"
echo "\$$ = $$"
echo $HOME
echo $PATH
echo $PWD
echo $PS1
