#include <iostream>
#include <vector>
struct Node
{
  unsigned int leader;
  unsigned int count;
};
std::vector<Node> nodes;
unsigned int find(unsigned int id)
{
  auto current = id;
  while (true)
  {
    auto leader = nodes[current].leader;
    if (leader == current)
    {
      if (nodes[id].leader != leader)
        nodes[id].leader = leader;

      return leader;
    }

    current = leader;
  }
}
void merge(unsigned int x, unsigned int y)
{
  auto rootX = find(x);
  auto rootY = find(y);

  if (rootX == rootY)
    return;

  if (nodes[rootX].count >= nodes[rootY].count)
  {
    nodes[rootX].count += nodes[rootY].count;
    nodes[rootY].leader = rootX;
  }
  else
  {
    nodes[rootY].count += nodes[rootX].count;
    nodes[rootX].leader = rootY;
  }
}
unsigned int generate()
{
  static std::vector<unsigned int> history;
  unsigned int current;
  if (history.size() < 55)
  {
    auto k = history.size() + 1;
    current = (300007ULL * k*k*k - 200003 * k + 100003) % 1000000;
  }
  else
  {
    current = (history[history.size() - 55] + history[history.size() - 24]) % 1000000;
    const size_t RemoveAtOnce = 100;
    if (history.size() > 55 + RemoveAtOnce)
      history.erase(history.begin(), history.begin() + RemoveAtOnce);
  }
  history.push_back(current);
  return current;
}
int main()
{
  unsigned int phone      = 524287;
  unsigned int percentage =     99;
  std::cin >> phone >> percentage;

  for (unsigned int i = 0; i < 1000000; i++)
    nodes.push_back({ i, 1 });
  unsigned int calls = 0;
  while (nodes[find(phone)].count < 1000000 * percentage / 100)
  {
    auto from = generate();
    auto to   = generate();
    if (from == to)
      continue;
    calls++;
    merge(from, to);
  }
  std::cout << calls << std::endl;
  return 0;
}
