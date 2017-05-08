# メモ
## 1. デバッグに便利なコマンド
1. 実行
   ./a.out < input.txt > output.txt
   
2. 間違えている部分を調べる
   colordiff answer.txt output.txt | less -R
   
3. 間違えている行の入力を表示する
   sed -n **p input.txt
   
4. 間違えている行だけ入力してみる
   sed -n **p input.txt | ./a.out