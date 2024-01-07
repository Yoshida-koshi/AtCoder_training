# AtCoder_training
![AtCoder ProblemsのTraining](https://kenkoooo.com/atcoder/#/training/Boot%20camp%20for%20Beginners/3)を解いています！
分からなかった問題の解説を実際に自分で書いてアウトプットしています。だいぶ長いかもしれないですが、ご参考までに。

## Hard Q1
### 問題
マスの情報を表す、LとRで構成された文字列<img src="https://latex.codecogs.com/svg.image?&space;S">が与えられます。
文字列<img src="https://latex.codecogs.com/svg.image?&space;S">の長さを<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;N">としたとき、<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;N">個のマスが左右一列に並んでおり、左から<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;i">番目のマスには<img src="https://latex.codecogs.com/svg.image?&space;S">の左から<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;i">番目の文字が書かれています。
ただし、左端のマスには必ずR、右端のマスには必ずLが書かれています。
はじめ、各マスには1人の子どもが居ます。
子どもたちはそれぞれ次の規則に従った移動を<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;10^{100}">回行います。
- 今居るマスに書かれた文字に従って1マス移動する。すなわち、今居るマスに書かれた文字がLのとき左隣のマスに、Rのとき右隣のマスに移動する。
<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;10^{100}">回の移動の後に各マスに居る子どもの人数を求めてください。
### 制約
- <img src="https://latex.codecogs.com/svg.image?&space;S">は長さ<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}2">以上<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}10^5">以下の文字列であり、<img src="https://latex.codecogs.com/svg.image?&space;S">の各文字はLまたはRである。
- <img src="https://latex.codecogs.com/svg.image?&space;S">の1文字目はR、<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;N">文字目はLである。
### 解説
RLで最終的にループするので、周期2で考えることができる。
マス目の最大が<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}10^5">なので、最大で<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}10^5">回移動すれば周期2のループ状態に入る。
よって、<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}10^5">回以上の<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}2^p(p>16)">回(今回は<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}p=32">)移動した時の各マスの子供の数を数えれば良い。
また、「最初<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;i">番目のマスにいた子供が<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}2^p">回移動した先のマス」を<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}dp(p,i)">とすると、<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}dp(p&plus;1,i)=dp(p,dp(p,i))">なので、これを<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}2^p">回移動する度に各マスで計算すれば「最初<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}&space;i">マスにいた子供が<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}2^{32}">回移動した先にいるマス」を求めることができる。
あとは求めたマスに必ず1人の子供が増えるので、そのマスに対して1増やすことを全てのマスに施せば良い。
### 計算量
今回は周期2のループ状態に入るので、「最初iマスにいた子供が<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}2^{32}">回移動した先にいるマス」を求める時が最大の計算量になり、その計算量は<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}O(NlogN)">となる。
最大で<img src="https://latex.codecogs.com/svg.image?\inline&space;\large&space;\bg{black}N=10^5">なので、実行時間2秒に十分間に合う。