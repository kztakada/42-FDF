#!/bin/bash

TARGETS="load_fdf"

# Generate test code
for t in $TARGETS; do
  cat src/src/$t.c test/t_$t.c > test/test_$t.c
done

# Run test
ceedling test:$TARGETS
# ceedling test:all

clean up
for t in $TARGETS; do
  rm -f test/test_$t.c
done