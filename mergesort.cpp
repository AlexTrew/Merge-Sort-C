#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

std::vector<int> Merge(const std::vector<int>& l, const std::vector<int>& r) {
	std::vector<int> merged_arr;
	merged_arr.reserve(l.size() + r.size());
	int i = 0;
	int j = 0;
	int k = 0;
	while (k < merged_arr.capacity())
	{
		if (i < l.size() && j < r.size()) {
			if (l[i] < r[j]) {
				merged_arr.push_back(l[i]);
				++i;
			}
			else {
				merged_arr.push_back(r[j]);
				++j;
			}
		}
		else if (i < l.size()) {
			merged_arr.push_back(l[i]);
			++i;
		}
		else if (j < r.size()) {
			merged_arr.push_back(r[j]);
			++j;
		}
		++k;
	}
	return merged_arr;
}

std::vector<int> MergeSort(const std::vector<int>& arr) {
	if (arr.size() > 1) {
		size_t middle = arr.size() / 2;
		std::vector<int> split_lo(arr.begin(), arr.begin() + middle);
		std::vector<int> split_hi(arr.begin() + middle, arr.end());
		return Merge(MergeSort(split_lo), MergeSort(split_hi));
	}
	return arr;
}

int main() {
	while (true) {
		std::cout << "Enter a sequence of numbers, separated by spaces. Type \"q\" to quit:" << std::endl;

		std::string input;
		std::getline(std::cin, input);
		if (std::regex_match(input, std::regex("([0-9]+\\ )+[0-9]+")) || input.compare("q") == 0) {
			if(input.compare("q") == 0){
				return 1;
            }

			std::istringstream iss(input);
			std::vector<std::string> numbers((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

			std::vector<int> sort_me;
			for (std::string& number : numbers) {
				sort_me.push_back(std::stoi(number));
			}

			std::vector<int> sorted = MergeSort(sort_me);
			std::string output;
			for (int num : sorted) {
				output = output + std::to_string(num) + " ";
			}
			std::cout << output << std::endl;	
		}
		else {
			std::cout << "input format error" << std::endl;
		}
	}
	return 0;

}