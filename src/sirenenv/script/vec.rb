#!/usr/bin/env ruby
# -*- mode:ruby; coding:utf-8 -*-

# �O�����x�N�g�� �N���X
class Vec

  attr_accessor :x, :y, :z

  # �R���X�g���N�^
  def initialize(x = 0, y = 0, z = 0)
    @x = x; @y = y; @z = z
  end

  # ��ʏ��擾���\�b�h ------

  # �z���Ԃ�
  def to_a
    [@x, @y, @z]
  end

  # �������Ԃ�
  def to_s
    "x = " + @x.to_s + ", y = " + @y.to_s + ", z = " + @z.to_s
  end

  # �x�N�g���v�Z���\�b�h ------

  # �傫��
  def size
    Math.sqrt(@x ** 2 + @y ** 2 + @z ** 2)
  end

  # ���K������Ă��邩
  def is_normal?
    self == normal
  end

  # ���K������
  def normal!
    f = 1.0 / size
    @x *= f; @y *= f; @z *= f
  end

  # ���K�������x�N�g����Ԃ�
  def normal
    f = 1.0 / size
    Vec.new @x * f, @y * f, @z * f
  end

  # ����
  def inner(other)
    a = normal
    b = other.normal
    a.x * b.x + a.y * b.y + a.z * b.z
  end

  # �O��
  def outer(other)
    a = normal
    b = other.normal
    Vec.new a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x
  end

  # ���]����
  def reverse!
    @x *= -1
    @y *= -1
    @z *= -1
  end

  # ���]�x�N�g����Ԃ�
  def reverse
    Vec.new @x * -1, @y * -1, @z * -1
  end

  # �����̊p�x(���W�A��)
  def sin(other)
    f = size * other.size
    if f != 0
        return outer(other).size * (1.0 / f)
    else
        return 0
    end
  end

  # �]���̊p�x(���W�A��)
  def cos(other)
    f = size * other.size
    if f != 0
        return inner(other) * (1.0 / f)
    else
        return 0
    end
  end

  # ���Z�q�̃I�[�o�[���C�h ------

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

  # �X�J���{
  def *(other)
    if !other.is_a?(Fixnum)
      raise
    end
    Vec.new @x * other, @y * other, @z * other
  end

  # �X�J����
  def /(other)
    if !other.is_a?(Fixnum)
      raise ""
    end
    if other == 0
      raise "division by zero"
    end
    Vec.new @x / other, @y / other, @z / other
  end

  # �ÓI���\�b�h ------

  def self.zero;  Vec.new 0, 0, 0 end # �[���x�N�g��
  def self.xaxis; Vec.new 1, 0, 0 end # X������
  def self.yaxis; Vec.new 0, 1, 0 end # Y������
  def self.zaxis; Vec.new 0, 0, 1 end # Z������

end

p Vec.new(10, 0, 0).is_normal?
