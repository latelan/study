#!/bin/bash

# 删除所有可执行文件

for FILE in *
do
	file $FILE | grep "ELF"  > /dev/null
	if [ $? -eq 0 ]; then
		rm $FILE
	fi
done
