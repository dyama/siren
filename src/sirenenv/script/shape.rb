#!/usr/bin/env ruby
# -*- mode:ruby; coding:utf-8 -*-

# Œ`ó ƒNƒ‰ƒX
class Shape

  attr_accessor :id

  def type
    Kernel::type(@id)
  end

  def bndbox
    Kernel::bndbox(@id)
  end

end

