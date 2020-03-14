#########################################################################
# File Name: prime.sh
# Author:
# mail: 
# Created Time: 2020年03月13日 星期五 15时23分28秒
#########################################################################
#!/bin/bash

for i in $(seq 0 1000); do
	prime[i]=0
done

ans=0
for ((i=2;i<=1000;i++)); do
	if [[ ${prime[i]} -eq 0 ]]; then
		let prime[0]++
		k=${prime[0]}
		prime[k]=$i
		let ans=$ans+$i
		#echo i=$i
	fi
	for ((j=1;j<=prime[0]&&prime[j]*i<=1000;j++)); do
		#if [[ prime[j]*i -ge 10 ]]; then
		#	break
		#fi
		let che=${prime[j]}*$i
		prime[che]=1;
		#echo prime[$che]=${prime[che]}
		if [[ i%prime[j] -eq 0 ]]; then
			break
		fi
	done
done

#echo ${prime[*]}
echo The ans=$ans


