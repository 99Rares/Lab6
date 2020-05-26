#pragma once
class FileRepo
{public:
	virtual void save_to_csv(string) = 0;

	virtual void save_to_html(string) = 0;
};

