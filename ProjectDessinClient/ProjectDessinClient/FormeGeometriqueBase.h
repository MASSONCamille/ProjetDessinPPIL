#pragma once
class FormeGeometriqueBase
{
protected:
	enum Couleurs {
		BLACK = 0,
		BLUE = 1,
		RED = 2,
		GREEN = 3,
		YELLOW = 4,
		CYAN = 5
	};

	Couleurs _color;

	inline FormeGeometriqueBase()
	{
		this->_color = BLACK;
	}
	inline FormeGeometriqueBase(const Couleurs c)
	{
		this->_color = c;
	}

	virtual int Dessiner() const;
	virtual int Traslation() const;
	virtual int Homothetie() const;
	virtual int Rotation() const;

public:
	virtual ~FormeGeometriqueBase();

	inline Couleurs getColor() const
	{
		return this->_color;
	}
	inline void setColor(const Couleurs c)
	{
		this->_color = c;
	}


};

