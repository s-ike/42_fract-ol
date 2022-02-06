# 42_fract-ol
miniLibXというX11描画ライブラリを用いたフラクタル画像の作成

以下のフラクタルを作成します。
- Mandelbrot set ([Wiki](https://en.wikipedia.org/wiki/Mandelbrot_set))
- Julia set ([Wiki](https://en.wikipedia.org/wiki/Julia_set))
- Burning Ship fractal ([Wiki](https://en.wikipedia.org/wiki/Burning_Ship_fractal))
- Tricorn ([Wiki](https://en.wikipedia.org/wiki/Tricorn_(mathematics)))

## Usage
mac, linuxにて動作検証しています

macではXQuartzをインストールしています
```
$ make

Mandelbrot:
$ ./fractol 1

Julia:
$ ./fractol 2 [real part] [imaginary part]

Burning Ship:
$ ./fractol 3

Tricorn:
$ ./fractol 4
```

## Demo
<img width="828" alt="スクリーンショット 2021-09-10 23 09 08" src="https://user-images.githubusercontent.com/13024418/152557883-370957d1-58b5-4bbb-a9d9-d92a30e2bcd0.png">
<img width="828" alt="スクリーンショット 2021-09-13 13 01 23" src="https://user-images.githubusercontent.com/13024418/152558243-b807fb5e-ade2-4db2-831a-0b6aef09dfc8.png">
