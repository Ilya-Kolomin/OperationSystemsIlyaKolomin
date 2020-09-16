if test ! -e file_ex2_fixed;
then
	echo 1 > file_ex2_fixed
fi

for i in `seq 1 500`;
do
	if ln file_ex2_fixed file_ex2_fixed.lock;
	then
		n=`tail -1 file_ex2_fixed`
		expr $n + 1 >> file_ex2_fixed
		rm file_ex2_fixed.lock
	fi
done
