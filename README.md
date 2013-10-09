zero4
=====

ＥＴロボコン2013リベンジ大会ゼロヨンレースで使用したプログラム

ゼロヨンレースとは長さ4ｍの直線コースをできるだけ早く走行するレースです。
このリポジトリにあるソースでリベンジ大会におけるゼロヨンレースで優勝しました。
以下でデプロイ方法と高速走行戦略についてまとめておきます。

高速走行戦略について
ゼロヨンレースでは、とにかく全速力で走行しかつ、できるだけ早くゴールに到達するために蛇行や斜めに走行せず、ゴールに
向かって一直線に走行することが大事である。

この２点をクリアするために、以下の３つの工夫をした
・高速走行のために尻尾走行を採用
高速走行するために、尻尾走行を採用した。
その結果倒立走行では最高速度45[cm/s]程度だったのが、尻尾走行では60cm/s程度になった

・高速走行のために片方のモータは常にＰＷＭ値１００を与える実装にした。
実装例(実際のコードはDrivenPart/WheelActuator.c の
WheelActuator_tail_running関数を参照)

if(旋回量が正){
		左モータＰＷＭ値 = 100;
		右モータＰＷＭ値 = 100- 旋回量;
	}
	else {
		左モータＰＷＭ値 = 100 - (-旋回量);
		右モータＰＷＭ値 = 100;
	}


・一直線に進むために向き制御を採用
車輪モータの回転角度から向きを計算し、そのその向きが常に0度になるように、フィードバック
制御をかけた。
これにより、走行体の向きが一定に保たれまっすぐ進むことが可能になる。
ただし、走行開始直後や走行中に車輪が空転した場合、向きがずれるのので、そのずれた角度のまままっすぐ進むので、
これは運に任せた。

・デプロイ方法

zero4/zero4 でmake all
コンパイルができたことを確認したら
sh appflash.shを実行


