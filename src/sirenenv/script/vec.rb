#!/usr/bin/env ruby
# -*- mode:ruby; coding:utf-8 -*-

# 三次元ベクトル クラス
class Vec

  attr_accessor :x, :y, :z

  # コンストラクタ
  def initialize(x = 0, y = 0, z = 0)
    @x = x; @y = y; @z = z
  end

  # 一般情報取得メソッド ------

  # 配列を返す
  def to_a
    [@x, @y, @z]
  end

  # 文字列を返す
  def to_s
    "x = " + @x.to_s + ", y = " + @y.to_s + ", z = " + @z.to_s
  end

  # ベクトル計算メソッド ------

  # 大きさ
  def size
    Math.sqrt(@x ** 2 + @y ** 2 + @z ** 2)
  end

  # 正規化されているか
  def is_normal?
    self == normal
  end

  # 正規化する
  def normal!
    f = 1.0 / size
    @x *= f; @y *= f; @z *= f
  end

  # 正規化したベクトルを返す
  def normal
    f = 1.0 / size
    Vec.new @x * f, @y * f, @z * f
  end

  # 内積
  def inner(other)
    a = normal
    b = other.normal
    a.x * b.x + a.y * b.y + a.z * b.z
  end

  # 外積
  def outer(other)
    a = normal
    b = other.normal
    Vec.new a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x
  end

  # 反転する
  def reverse!
    @x *= -1
    @y *= -1
    @z *= -1
  end

  # 反転ベクトルを返す
  def reverse
    Vec.new @x * -1, @y * -1, @z * -1
  end

  # 正弦の角度(ラジアン)
  def sin(other)
    f = size * other.size
    if f != 0
        return outer(other).size * (1.0 / f)
    else
        return 0
    end
  end

  # 余弦の角度(ラジアン)
  def cos(other)
    f = size * other.size
    if f != 0
        return inner(other) * (1.0 / f)
    else
        return 0
    end
  end

  # 演算子のオーバーライド ------

  def ==(other)
    @x == other.x && @y == other.y && @z == other.z
  end

  def !=(other)
    !(self == other)
  end

  def +(other)
    Vec.new @x + other.x, @y + other.y, @z + other.z
  end

  def -(other)
    Vec.new @x - other.x, @y - other.y, @z - other.z
  end

  # スカラ倍
  def *(other)
    if !other.is_a?(Fixnum)
      raise
    end
    Vec.new @x * other, @y * other, @z * other
  end

  # スカラ割
  def /(other)
    if !other.is_a?(Fixnum)
      raise ""
    end
    if other == 0
      raise "division by zero"
    end
    Vec.new @x / other, @y / other, @z / other
  end

  # 静的メソッド ------

  def self.zero;  Vec.new 0, 0, 0 end # ゼロベクトル
  def self.xaxis; Vec.new 1, 0, 0 end # X軸方向
  def self.yaxis; Vec.new 0, 1, 0 end # Y軸方向
  def self.zaxis; Vec.new 0, 0, 1 end # Z軸方向

end

p Vec.new(10, 0, 0).is_normal?
