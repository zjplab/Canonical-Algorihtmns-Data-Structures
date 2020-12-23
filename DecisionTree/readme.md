## ID3

ID3决策树的输入训练数据是一组带有类别标记的样本，构造的结果是一棵多叉树。树的分支节点一般表示为一个逻辑判断，如形式为a=aj的逻辑判断，其中a是属性，aj是该属性的所有取值。如果选择在某一节点上用哪个特征呢？标准是在该节点上选取能对该节点处的训练数据进行最优划分的属性。划分的标准是信息增益（Information Gain），即划分前后数据集的熵的差异。取能带来最大信息增益的那个feature作为当前划分标准。

![](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5E%7Bm%7D%7Bp_i%7Dlog_2%28pi%29) 这里p是针对目标变量，对于二分类问题，m=2。 即“熵”

对于每一个特征，相应的Empirical Conditional Entropy(经验条件熵)就是

![](https://www.zhihu.com/equation?tex=Info_A%28D%29+%3D+%5Csum_%7Bj%3D1%7D%5E%7Bv%7D%7B%5Cfrac%7B%7CD_j%7C%7D%7B%7CD%7C%7D%7D%2Ainfo%28D_j%29)这里的Dj代表该特征的某一个category对应的子集，比如一个特征的值是{1,1,1,2,2,4,4,4,4},那么就有D_1={1,1,1}, D_2={2,2}, D_3={4,4,4,4}, 所以|D_1|/|D| = 3/9, |D_2|\|D| = 2/9, |D_3|\|D| = 4/9. 这里的info(D_j) 就是每个D子集对应的目标变量的info(D). 即“条件熵”

每一个特征的info gain =parent节点的info(D) - 当前按此特征划分的info(D) 即“信息增益”

（划分标准的计算过程可参考这篇：决策树ID3、C4.5、CART算法：信息熵，区别，剪枝理论总结 - Rocky - CSDN博客 但是这篇在介绍连续型变量时把ID3和C4.5弄混了，所以建议只参考这篇的数学计算过程。）

如果在该节点的父节点或者祖先中用了某个属性，则这个用过的属性就不再使用。选择好最优属性后，假设该属性有N个取值，则为该节点建立N个分支，将相应的训练数据传递到这N个分支中，递归进行，停止条件为：

（1）该节点的所有样本属于同一类，该节点成为叶节点，存放相应的类别。（2）所有的属性都已被父节点或祖先使用。这种情况下，该节点成为叶节点，并以样本中元组个数最多的类别作为类别标记，同时也可以存放该结点样本的类别分布。

最后重申一遍ID3的原理：在ID3中，每次根据“最大信息熵增益”选取当前最佳的特征来分割数据，并按照该特征的所有取值来切分，也就是说如果一个特征有4种取值，数据将被切分4份，一旦按某特征切分后，该特征在之后的算法执行中，将不再起作用，所以有观点认为这种切分方式过于迅速。

ID3的特点：（1）容易造成过度拟合。（2）使用标称型数据，但是很难处理连续型数据。

## C4.5