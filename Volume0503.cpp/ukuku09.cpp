#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <iomanip>
#include <algorithm>

#include <type_traits>
#include <climits>
#include <string>
using namespace std;


//#define int long long

#define all(v) begin(v), end(v)
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define reps(i,s,n) for(int i = s; i < (int)(n); ++i)

template <class T1, class T2>
void chmin(T1& a, T2 b) { if(a > b) a = b; }

template <class T1, class T2>
void chmax(T1& a, T2 b) { if(a < b) a = b; }

using pint = pair<int,int>;
using tint = tuple<int,int,int>;
using vint = vector<int>;


int n, m;
int bit[3];


template <class T>
std::string printBits(T n) {
	static_assert(is_integral<T>::value, "Type T must be numeric!\n");

	std::string ret {};

	void* p = &n;
	for(std::size_t i = sizeof(n) - 1; i >= 0; --i) {
		unsigned char* uptr = (unsigned char*)(p);

		uptr += i;
		for(std::size_t j = 7; j >= 0; --j) {
			ret += ((*uptr) & (0x1 << j) ? "1" : "0");
		}
	}

	return ret;
}


int solve(int A, int B, int C) {
	if(A == 0 && B == 0) return 0;
	if(C & 1) return solve(A>>1,B>>1,C>>1);
	if(B & 1) return solve(C>>1,B>>1,A>>1) + solve((A|B|C)>>1,0,0) + 1;
	if(A & 1) return solve(A>>1,B>>1,C>>1) + 2 * (solve((A|B|C)>>1,0,0) + 1);
}

/*
signed main() {
	cin.tie(0);

	ios_base::sync_with_stdio(0);

	cout << fixed << setprecision(12);

	while(cin >> n >> m, n) {
		rep(i, 3) {
			bit[i] = 0;

			int k; cin >> k;
			rep(j, k) {
				int c; cin >> c; --c;
				bit[i] |= 1 << c;
			}
		}

		int ans = min(solve(bit[0], bit[1], bit[2]),solve(bit[2], bit[1], bit[0]));

		cout << (ans > m ? -1 : ans) << endl;
	}

	return 0;
}
*/

auto main() -> int {
	uint32_t n = 255u;

	std::cout << printBits(n) << std::endl;

	return 0;
}


