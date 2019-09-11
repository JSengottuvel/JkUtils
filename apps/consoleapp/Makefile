# MIT License
#
# Copyright (c) [2019] [Jayakumar Sengottuvel] [www.jayakumar.de]
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

TARGETNAME=consoleapp

PROJECT_ROOT=../..

JKUTILS_ROOT=$(PROJECT_ROOT)/c

IDIR = \
	-I. \
	-I$(PROJECT_ROOT) \
	-I$(JKUTILS_ROOT) \

CC=gcc
CFLAGS=-I$(IDIR)

ODIR=.
LDIR =$(PROJECT_ROOT)/Library

LIBS=-lm

_DEPS = $(wildcard $(JKUTILS_ROOT)/*.h)
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

CSRC = \
	$(wildcard $(JKUTILS_ROOT)/jkchex.c) \
    $(wildcard $(JKUTILS_ROOT)/jkconfigstore.c) \
    $(wildcard $(JKUTILS_ROOT)/jkcstring.c) \
    ./consoleapp.c \

OBJ =  $(CSRC:.c=.o)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGETNAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJ)  $(TARGETNAME)
