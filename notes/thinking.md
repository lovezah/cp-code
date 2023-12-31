## [Codeforces Round 895 (Div. 3) E. Data Structures Fan](https://codeforces.com/contest/1872/problem/E)
* 给一个序列n个数和一个binary string s。支持两种操作，第一个是给l和r。将s[l::r]中1变0，0变1。第二个给g，查询s中所有为g(0<=g<=1)的下标在序列对应位置的xor和
* 用线段树可以做，维护所有0位置的异或和：vals[0]和所有1位置的异或和：vals[1]，以及每个区间的0的异或和和1的异或和，懒标记传一下可做
* 正解：我们查询的不是vals[0]就是vals[1]。并且vals[0]^vals[1]是不会改变的，就等于整个序列的异或和。因此我们可以只维护vals[0]，简化操作。操作一个区间，vals[0]如何变化？区间内所有的0都会消失，所有的1都会去贡献vals[0]，因此只需要用vals[0]异或上操作区间的异或和即可。操作区间的异或和=区间内0的异或和^区间内1的异或和。可以用前缀和加速。

## [Educational Codeforces Round 58 F. Trucks and Cities](https://codeforces.com/contest/1101/problem/F)
* n个城市在一条线上，每个城市到原点的距离为a[i]，且都在原点右侧。有m个卡车，每个卡车从s[i]城市开到f[i]城市，公里耗油c[i]且每辆卡车最多加r[i]次油。最开始每辆车都是满油。你想找最小的卡车油箱V满足所有卡车都能到达目的地。(n<=400,m<=250000,a[i]<=1e9)
* 暴力做法可以对每辆卡车二分，找到当前卡车最小合适油箱。代价是O(m\*n\*log)过于极限。**有个结论：对于一个随机序列，其前缀最大值仅有log个**,因此我们不用对每个卡车都二分。因为如果当前维护的答案可以让当前卡车通过，那当前维护的答案就是瓶颈，不需要用这辆卡车更新。所以可以random_shuffle一下。总代价为O(n\*log\*logm)

## [Educational Codeforces Round 58 G. (Zero XOR Subset)-less](https://codeforces.com/contest/1101/problem/G)
* 给一个数组a，n个数。尽可能切这个数组，满足不存在任选若干个(>0)segment，其异或和为0.
* 对于区间异或和，可以考虑前缀和一下。
* 对其前缀和序列b来看。我们可以以此插入线性基中。如果能插入答案加1。假设b[0],b[1],b[2]...b[m]为插入成功的a数组下标。这是一个极大无关组。任意两个数异或都不为0。因为如果为0则说明两者相同，与线性无关矛盾。b[i]^b[i+1]一定能由线性基中其他元素表示（可以理解为两个基不可能表示出第三个基）.同时他的含义表示a数组中一段子数组的异或和。因此任意个都不为0。

## [Codeforces Round 863 (Div. 3) E. Living Sequence](https://codeforces.com/contest/1811/problem/E)
* 构造一个无尽的序列，要求序列里的数字的数位不能有4，找到序列的第k个元素，k<=1e12
* 想到二分加数位dp，但是好麻烦
* 正解是，k是十进制，因为少了1位，所以将其转化为9进制。又不能有4，所以将4-8映射成5-9即可。