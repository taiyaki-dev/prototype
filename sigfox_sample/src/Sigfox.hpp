#include "Arduino.h"

class Sigfox
{
	public:
	bool Initialize();
	bool SendMessage(const String message);
  bool Finalize();
};
