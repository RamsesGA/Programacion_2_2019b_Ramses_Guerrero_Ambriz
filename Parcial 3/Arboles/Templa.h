#pragma once

#include "Libraries.h"
#include "Person.h"

#define TEMPLATE(c,t) template class c<t>;

//Arbol
#ifdef TREE
#define TCLASS Tree
#define OSTREAM(type) ostream & operator << (ostream &_out, Tree<type> &_n)
{

}
#define ISTREAM(type) istream &operator >> (istream &_inp, Tree <type> &_n)
{

}

//Node
#ifdef NODE
#define TCLASS Node
#define OSTREAM(type) ostream &operator << (ostream &_out, const Node <type>)
{

}
#define ISTREAM(type) istream &operator >> (istream &_in, const Node <type)
{

}