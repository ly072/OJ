##	基础知识

*	[什么是红黑树](http://www.cnblogs.com/fornever/archive/2011/12/02/2270692.html)

个人以为，如果对红黑树的概念没有什么了解，这道题很难做对。我也只是看了这篇文章以后，对红黑树有了感性的了解。

##	做题

*	首先构造BST

	将原始pre数列排序，然后利用BST中序是递增数列的特点，进行逐个对比

	如果出现不同，那么这个不是BST，直接输出gg

*	接着逐个检查属性1~5

	只检查属性1~4的话，只能拿6分，而第5条属性，刚才说了，如果没有概念上的了解，光看这个英文（比如第3条，此leaf非彼leaf，画了个括号的NULL也看不懂，而4和5又与3有关），比较难写出相应的逻辑。所以建议先看完上面链接的文章。

*	其他步骤，具体看代码，慢慢补充。