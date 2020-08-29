#ifndef HEADER_H
#define HEADER_H

#include <cstddef>
#include <cstring>


#define deque_define(type)                         \
	struct deque_##type##_iter;	                   \
	struct deque_##type {                          \
		char type_name[strlen("deque_"#type)+1];   \
		type *elements;                            \
		long head;                                 \
		long tail;                                 \
		size_t size;                               \
		void (*push_back)(deque_##type *);         \
		void (*push_front)(deque_##type *);        \
		void (*pop_back)(deque_##type *);          \
		void (*pop_front)(deque_##type *);         \
	};                                             \
	struct deque_##type##iter {                    \
		deque_##type *deq;                         \
		int size;                                  \
		int current;                               \
		void (*increment)(deque_##type##_iter *);  \
		void (*decrement)(deque_##type##_iter *);  \
	};                                             \

#endif