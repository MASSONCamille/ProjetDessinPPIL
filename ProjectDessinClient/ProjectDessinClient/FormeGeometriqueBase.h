#pragma once
class FormeGeometriqueBase
{
public:
	enum Couleurs {
		BLACK = 0,
		BLUE = 1,
		RED = 2,
		GREEN = 3,
		YELLOW = 4,
		CYAN = 5
	};

	virtual ~FormeGeometriqueBase();

	inline Couleurs getColor() const
	{
		return this->_color;
	}
	inline void setColor(const Couleurs c)
	{
		this->_color = c;
	}

protected:
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

};

