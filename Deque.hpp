#ifndef HEADER_H
#define HEADER_H
#include <cstring>

// Implementation of a generic double ended queue

#define MAX_SIZE 10000000	// 10 million
#define block_size(type) sizeof(type)*MAX_SIZE
#define alloc(type) (type *)malloc(block_size(type))
#define START_SIZE 100
#define START_ARRAY 50
#define MODULO(X,N)  (((X) < 0) ? (((X) % (N)) + (N)) : ((X) % (N)))

#define Deque_DEFINE(type)                                                            \
	struct Deque_##type##_Iterator;                                                   \
	struct Deque_##type {                                                             \
		char type_name[strlen("Deque_"#type)+1];                                      \
		type *elements;                                                               \
		long head;                                                                    \
		long tail;                                                                    \
		size_t element_count;                                                         \
		long array_size;                                                              \
		void (*push_back)(Deque_##type *);                                            \
		void (*push_front)(Deque_##type *);                                           \
		void (*pop_back)(Deque_##type *, type);                                       \
		void (*pop_front)(Deque_##type *, type);                                      \
		size_t (*size)(Deque_##type *);                                               \
		void (*clear)(Deque_##type *);                                                \
		bool (*equal)(Deque_##type * a, Deque_##type * b);                            \
		type &(*at)(Deque_##type, int);                                               \
		type &(*back)(Deque_##type *);                                                \
		type &(*front)(Deque_##type *);                                               \
		Deque_##type##_Iterator (*begin)(Deque_##type *);                             \
		Deque_##type##_Iterator (*end)(Deque_##type *);                               \
		void (*sort)(Deque_##type, Deque_##type##_Iterator, Deque_##type##_Iterator); \
		void (*comparator)(const type &, const type &);                               \
	};                                                                                \
	struct Deque_##type##_Iterator {                                                  \
		Deque_##type *deq;                                                            \
		int size;                                                                     \
		int current;                                                                  \
		void (*increment)(Deque_##type##_Iterator *);                                 \
		void (*decrement)(Deque_##type##_Iterator *);                                 \
	};                                                                                \
	void Deque_##type##_dtor(Deque_##type *dp) {                                      \
		free (dp->elements);                                                          \
	}                                                                                 \
	bool Deque_##type##_empty(Deque_##type *dp) {                                     \
		return (dp->size(dp) == 0);                                                   \
	}                                                                                 \
	void Deque_##type##_pop_back(Deque_##type *dp) {                                  \
		if (dp->tail == 0) {                                                          \
			dp->tail = dp->array_size-1;                                              \
		}                                                                             \
	}                                                                                 \
	void Deque_##type##_pop_front(Deque_##type *dp) {                                 \
		if (dp->head == 0) {                                                          \
			dp->head = dp->array_size-1;                                              \
		} else {                                                                      \
			dp->head++;                                                               \
		}                                                                             \
		dp->element_count--;                                                          \
	}                                                                                 \
	void Deque_##type##_push_back(Deque_##type *dp, type val) {                       \
		if (MODULO(dp->tail+2, dp->array_size) == dp->head && dp->element_count > 1) {\
			int new_size = dp->array_size * 2;                                        \
			type *new_array = (type *)realloc(dp->elements, new_size * sizeof(type)); \
			if(new_array) {                                                           \
				for(long i=0; i<dp->head; i++) {                                      \
					new_array[dp->array_size] = new_array[i];                         \
					dp->array_size++;                                                 \
				}                                                                     \
				dp->tail = MODULO(dp->array_size-1, dp->array_size);                  \
			} else {                                                                  \
				fprintf(stderr, "realloc failed\n");                                  \
				exit(1);                                                              \
			}                                                                         \
			/* push element into deq */                                               \
			new_array[dp->tail] = val;                                                \
			dp->element_count++;                                                      \
			dp->array_size = new_size;                                                \
			dp->elements = new_array;                                                 \
		} else {                                                                      \
			int nct = MODULO(dp->tail+1, dp->array_size);                             \
			dp->elements[nct] = val;                                                  \
			if(dp->element_count++ == 0) {                                            \
				dp->head = nct;                                                       \
			}                                                                         \
		}                                                                             \
	}                                                                                 \

#endif