#ifndef MUVELETEK_H
#define MUVELETEK_H

	class Muveletek {
	public:
		virtual float getOsszeg() const = 0;
		virtual float getKamat() const = 0;
		virtual void letet(float befizetettOsszeg) = 0;
		virtual void kivet(float kivettOsszeg) = 0;

		virtual ~Muveletek() {}
	
	};
#endif //MUVELETEK_H