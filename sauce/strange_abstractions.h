#ifndef COM_ONEISH_STRANGE_ABSTRACTIONS_H
#define COM_ONEISH_STRANGE_ABSTRACTIONS_H

// abstractions

#include "generated/define_strange_any_a.hpp"

#define ___root___ any_a<>

#include "strange_forward_const_iterator_a.h"

#define ___derived___ forward_const_iterator_a<>
#include "strange_forward_const_iterator_data_a.h"

#include "strange_forward_iterator_a.h"

#define ___derived___ forward_iterator_a<>
#include "strange_forward_iterator_data_a.h"

#define ___derived___ forward_const_iterator_a<>
#include "strange_bidirectional_const_iterator_a.h"

#define ___derived___ bidirectional_const_iterator_a<>
#include "strange_bidirectional_const_iterator_data_a.h"

#define ___derived___ forward_iterator_a<>
#include "strange_bidirectional_iterator_a.h"

#define ___derived___ bidirectional_iterator_a<>
#include "strange_bidirectional_iterator_data_a.h"

#define ___derived___ bidirectional_const_iterator_a<>
#include "strange_random_access_const_iterator_a.h"

#define ___derived___ random_access_const_iterator_a<>
#include "strange_random_access_const_iterator_data_a.h"

#define ___derived___ bidirectional_iterator_a<>
#include "strange_random_access_iterator_a.h"

#define ___derived___ random_access_iterator_a<>
#include "strange_random_access_iterator_data_a.h"

#include "strange_misunderstanding_a.h"

#include "strange_range_a.h"

#include "strange_range_of_a.h"

#define ___derived___ range_a<>
#include "strange_collection_a.h"

#define ___derived___ collection_a<>
#include "strange_shoal_a.h"

#define ___derived___ shoal_a<>
#include "strange_ordered_shoal_a.h"

#define ___derived___ shoal_a<>
#include "strange_unordered_shoal_a.h"

#define ___derived___ collection_a<>
#include "strange_herd_a.h"

#define ___derived___ herd_a<>
#include "strange_ordered_herd_a.h"

#define ___derived___ herd_a<>
#include "strange_unordered_herd_a.h"

#include "strange_data_a.h"

#include "strange_number_a.h"

#define ___derived___ number_a<>
#include "strange_number_data_a.h"

#define ___derived___ collection_a<>
#include "strange_inventory_a.h"

#define ___derived___ inventory_a<>
#include "strange_flock_a.h"

#define ___derived___ inventory_a<>
#include "strange_squad_a.h"

#define ___derived___ inventory_a<>
#include "strange_lake_a.h"

#define ___derived___ inventory_a<>
#include "strange_brook_a.h"

#define ___derived___ range_a<>
#include "strange_river_a.h"

#include "strange_symbol_a.h"

#define ___derived___ symbol_a<>
#include "strange_cat_a.h"

#define ___derived___ cat_a<>
#include "strange_kind_a.h"

#include "strange_token_a.h"

#include "strange_operation_a.h"

#define ___derived___ operation_a<>
#include "strange_expression_a.h"

#include "strange_parser_a.h"

#undef ___root___
#undef ___derived___

#endif
