#ifndef COM_ONEISH_STRANGE_NUMBER_DATA_FORWARD_A_H
#define COM_ONEISH_STRANGE_NUMBER_DATA_FORWARD_A_H

namespace strange
{

template <typename _1_>
class number_data_a;

template <typename _1_ = void>
using number_data_int8_a = number_data_a<int8_t>;

template <typename _1_ = void>
using number_data_int64_a = number_data_a<int64_t>;

} // namespace strange

#endif
