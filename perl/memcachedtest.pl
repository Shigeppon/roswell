#!/usr/bin/perl

use strict;
use warnings;
use Cache::Memcached;

my $key = "foo";
my $value = "baraaa";
my $expires = 3600; # 1 hour
my $memcached = Cache::Memcached->new({
    servers => ["mihoko:11211"],
    compress_threshold => 10_000
  });

$memcached->add($key, $value, $expires);
my $ret = $memcached->get($key);
print "$ret\n";
