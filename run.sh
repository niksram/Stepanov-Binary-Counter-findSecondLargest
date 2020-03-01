make
valgrind --leak-check=full ./a.out<checks/session5_sort_ip1.txt
echo;
cat checks/session5_sort_ip1.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip2.txt
echo;
cat checks/session5_sort_ip2.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip3.txt
echo;
cat checks/session5_sort_ip3.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand032k.txt
echo;
cat checks/session5_sort_ip_rand032k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand064k.txt
echo;
cat checks/session5_sort_ip_rand064k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand096k.txt
echo;
cat checks/session5_sort_ip_rand096k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand128k.txt
echo;
cat checks/session5_sort_ip_rand128k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand160k.txt
echo
cat checks/session5_sort_ip_rand160k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand192k.txt
echo
cat checks/session5_sort_ip_rand192k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand224k.txt
echo;
cat checks/session5_sort_ip_rand224k.txt |sort -nr|head -n 3
read
echo "exp"
valgrind --leak-check=full ./a.out<checks/session5_sort_ip_rand256k.txt
echo;
cat checks/session5_sort_ip_rand256k.txt |sort -nr|head -n 3
read
echo "exp"
make clean