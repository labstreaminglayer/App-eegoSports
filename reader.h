#pragma once
#include <QObject>

namespace eemagine { namespace sdk { class amplifier; class stream; }}

class Reader : public QObject {
	Q_OBJECT
public:
	Reader(): stop(false) {}
	virtual ~Reader() override;

	public slots:
	void read();
	void setStop(bool stop) {
		this->stop = stop;
	}
	void setParams(int samplingRate);

signals:
	void finished();
	void timeout();
	void ampNotFound();
	void connectionLost();

private:
	eemagine::sdk::amplifier* amp;
	eemagine::sdk::stream* eegStream;
	unsigned int samplingRate;
	bool stop;
};
