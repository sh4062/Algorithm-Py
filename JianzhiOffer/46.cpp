//约瑟夫环
/*
如果只求最后一个报数胜利者的话，我们可以用数学归纳法解决该问题，为了讨      论方便，先把问题稍微改变一下，并不影响原意：
问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人 继续从0开始报数。求胜利者的编号。
我们知道第一个人(编号一定是m%n-1) 出列之后，剩下的n-1个人组成了一个新      的约瑟夫环（以编号为k=m%n的人开始）:
k  k+1  k+2  ... n-2, n-1, 0, 1, 2, ... k-2并且从k开始报0。
现在我们把他们的编号做一下转换：
k     --> 0
k+1   --> 1
k+2   --> 2
...
...
k-2   --> n-2
k-1   --> n-1
变换后就完完全全成为了(n-1)个人报数的子问题，假如我们知道这个子问题的解： 例如x是最终的胜利者，那么根据上面这个表把这个x变回去不刚好就是n个人情 况的解吗？！！变回去的公式很简单，相信大家都可以推出来：x'=(x+k)%n。
令f[i]表示i个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]。
递推公式
f[1]=0;
f[i]=(f[i-1]+m)%i;  (i>1)
有了这个公式，我们要做的就是从1-n顺序算出f[i]的数值，最后结果是f[n]。 因为实际生活中编号总是从1开始，我们输出f[n]+1。*/
class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n==0)
            return -1;
        if(n==1)
            return 0;
        else
            return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};