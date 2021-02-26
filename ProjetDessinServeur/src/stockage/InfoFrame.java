package stockage;

import java.awt.Frame;

public class InfoFrame {
	int noConnexion;
	String noFrame;
	Frame fen;

	public InfoFrame() {
		this.noConnexion = -1;
		this.noFrame = "-1";
		this.fen = new Frame();
	}

	public InfoFrame(int noConnexion, String noFrame, Frame fen) {
		super();
		this.noConnexion = noConnexion;
		this.noFrame = noFrame;
		this.fen = fen;
	}

	public int getNoConnexion() {
		return noConnexion;
	}

	public void setNoConnexion(int noConnexion) {
		this.noConnexion = noConnexion;
	}

	public String getNoFrame() {
		return noFrame;
	}

	public void setNoFrame(String noFrame) {
		this.noFrame = noFrame;
	}

	public Frame getFen() {
		return fen;
	}

	public void setFen(Frame fen) {
		this.fen = fen;
	}

	@Override
	public String toString() {
		return "InfoFrame [noConnexion=" + noConnexion + ", noFrame=" + noFrame + "]";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		InfoFrame other = (InfoFrame) obj;
		if (noConnexion != other.noConnexion)
			return false;
		if (noFrame == null) {
			if (other.noFrame != null)
				return false;
		} else if (!noFrame.equals(other.noFrame))
			return false;
		return true;
	}

}
