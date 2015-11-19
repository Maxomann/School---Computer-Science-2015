#include "VigenereCrypter.h"
using namespace std;
using namespace sf;
using namespace tgui;

namespace kg
{
	VigenereCrypter::VigenereCrypter( const std::shared_ptr<AlphabetConverter>& alphabetConverter )
		:SymmetricCrypter<std::vector<Restklasse>>( alphabetConverter )
	{ }

	std::vector<Restklasse> VigenereCrypter::getInverseKey( const std::vector<Restklasse>& key ) const
	{
		std::vector<Restklasse> retVal;

		for( const auto& el : key )
			retVal.push_back( el*-1 );

		return retVal;
	}

	std::vector<Restklasse> VigenereCrypter::encrypt( const std::vector<Restklasse>& key, const std::vector<Restklasse>& input )
	{
		unsigned int positionInKey = 0;

		vector<Restklasse> retVal;

		for( const auto& el : input )
		{
			retVal.push_back( el + key.at( positionInKey ) );

			//increment key
			positionInKey++;
			positionInKey %= key.size();
		}

		return retVal;
	}

	std::vector<Restklasse> VigenereCrypter::decrypt( const std::vector<Restklasse>& key, const std::vector<Restklasse>& input )
	{
		auto inverseKey = getInverseKey( key );

		return encrypt( inverseKey, input );
	}
}