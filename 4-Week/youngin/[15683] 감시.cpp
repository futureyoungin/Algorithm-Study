#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>


using namespace std;

#define EAST 1
#define WEST -1
#define SOUTH 2
#define NORTH -2

int N, M;
int room[8][8];
int min_zero = 1000000000;
vector<pair<int, pair<int, int>>> camera;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 5)
				camera.push_back(make_pair(room[i][j], make_pair(i, j)));
		}
}

int find_zero() {
	int zero = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (room[i][j] == 0)
				zero++;
	return zero;
}

void laser(int camera_y, int camera_x, int direction) {
	if (direction == EAST) {
		for (int i = camera_x + 1; i < M; i++) {
			if (room[camera_y][i] == 6)
				break;
			else if (room[camera_y][i] != 0)
				continue;
			else {
				room[camera_y][i] = 10;
			}
		}
	}
	else if (direction == WEST) {
		for (int i = camera_x - 1; i >= 0; i--) {
			if (room[camera_y][i] == 6)
				break;
			else if (room[camera_y][i] != 0)
				continue;
			else {
				room[camera_y][i] = 10;
			}
		}
	}
	else if (direction == SOUTH) {
		for (int i = camera_y + 1; i < N; i++) {
			if (room[i][camera_x] == 6)
				break;
			else if (room[i][camera_x] != 0)
				continue;
			else {
				room[i][camera_x] = 10;
			}
		}
	}
	else if (direction == NORTH) {
		for (int i = camera_y -1; i >= 0; i--) {
			if (room[i][camera_x] == 6)
				break;
			else if (room[i][camera_x] != 0)
				continue;
			else {
				room[i][camera_x] = 10;
			}
		}
	}
}

void act_camera(int n_camera, int camera_y, int camera_x, int direction) {
	if (n_camera == 1)
		laser(camera_y, camera_x, direction);
	else if (n_camera == 2) {
		laser(camera_y, camera_x, direction);
		laser(camera_y, camera_x, -1 * direction);
	}
	else if (n_camera == 3) {
		if (direction == EAST || direction == WEST) {
			laser(camera_y, camera_x, direction);
			laser(camera_y, camera_x, -2 * direction);
		}
		else if (direction == NORTH || direction == SOUTH) {
			laser(camera_y, camera_x, direction);
			laser(camera_y, camera_x, direction / 2);
		}
	}
	else if (n_camera == 4) {
		for (int i = NORTH; i <= SOUTH; i++) {
			if (i == 0 || i == direction)
				continue;
			laser(camera_y, camera_x, i);
		}
	}
	else if (n_camera == 5) {
		laser(camera_y, camera_x, EAST);
		laser(camera_y, camera_x, WEST);
		laser(camera_y, camera_x, NORTH);
		laser(camera_y, camera_x, SOUTH);
	}

}

void dfs(int num_camera) {
	if (num_camera == camera.size()) {
		min_zero = min(min_zero, find_zero());
		return;
	}
	int copy_room[8][8];
	copy(&room[0][0], &room[0][0] + 64, &copy_room[0][0]);
	int n_camera = camera[num_camera].first;
	int camera_y = camera[num_camera].second.first;
	int camera_x = camera[num_camera].second.second;
	for (int direction = NORTH; direction <= SOUTH; direction++) {
		if (direction == 0) continue;
		act_camera(n_camera, camera_y, camera_x, direction);
		dfs(++num_camera);
		copy(&copy_room[0][0], &copy_room[0][0] + 64, &room[0][0]);
		num_camera--;
	}
}

int main() {
	input();
	dfs(0);
	cout << min_zero;
	return 0;
}