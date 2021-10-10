#ifndef COM_ONEISH__STRANGE__CLASSIFICATION_E_H
#define COM_ONEISH__STRANGE__CLASSIFICATION_E_H

namespace strange
{
	enum class classification_e
	{
		name,
		symbol_literal,
		text_literal,
		int_literal,
		float_literal,
		comment,
		punctuation,
		mistake,
	};
}

#endif
