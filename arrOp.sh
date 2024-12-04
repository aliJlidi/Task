#!bash/bin 
N=0
TakeInput(){
read "Please specify an array size " N 

# Number validation 
reg_ex='^[0-9]+$'

if [[ ! $N =~ $reg_ex ] ]; then
echo "N must be a number" 1>&2
exit 1
fi 
# positive number validtion
if [ $N -le 0 ]; then
echo "N must be positive" 1>&2
exit 1
fi 
}
#define an array 
declare -a arr 
fillArray(){
    for (( i=0 ; i<$N ; i++ )); do 
   # Generate a random from 1-100 and assign it to the array element 
   arr[$i]=$((RANDOM %1 00 + 1))
done 
}
min=0
max=0
sum=0

minMaxSum(){
    for (( i=0 ; i<$N ; i++ )); do 
   if [[ $min -gt arr[$i]]]; then 
   min=$i
   fi
   if [[ $max -lt arr[$i] ]]; then
   max=$i
   fi
   sum=$(( sum + arr[$i]))
done 
}




TakeInput
fillArray
minMaxSum
printResults




