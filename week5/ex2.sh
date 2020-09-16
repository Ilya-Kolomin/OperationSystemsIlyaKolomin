if test ! -e file_ex2;
then
	echo 1 > file_ex2
fi

for i in `seq 1 500`;
do
	n=`tail -1 file_ex2`
	expr $n + 1 >> file_ex2
done
