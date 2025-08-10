# Pilgrimage Cost Optimization Using Graph Theory

## 📌 Project Overview
This project helps pilgrims plan their journeys in the most **cost-effective** way by applying **Graph Theory** concepts. Using algorithms such as **Dijkstra's Algorithm**, the system calculates the shortest or least expensive routes between pilgrimage sites while ensuring timely arrivals.

---

## 🎯 Objective
- Minimize **travel costs** for pilgrims.
- Provide **optimal route suggestions** based on train fares.
- Ensure **timely arrivals** at destinations.

---

## 🛠 Features
- **Graph-based route modeling** with cities as vertices and travel costs as edge weights.
- **Dijkstra's Algorithm** for finding the shortest (minimum cost) path.
- Multiple route suggestions with their respective costs.
- Clearly marked **minimum-cost routes** for quick decision-making.

---

## 📜 Algorithm (Pseudo Code)

while Q is not empty:
    U <- Extract MIN from Q
    for each unvisited neighbour V of U:
        tempDistance <- distance[U] + edge_weight(U, V)
        if tempDistance < distance[V]:
            distance[V] <- tempDistance
            previous[V] <- U

return distance[], previous[]

## 🚉 Example Routes & Minimum Costs

### From Sambalpur to Veroval (Somnath Temple)
- **Optimal**: Sambalpur → Surat → Veroval — **₹930** (Train) ✅
- Sambalpur → Vadodora → Veroval — ₹1020
- Sambalpur → Ujjain → Veroval — ₹1050

### From Sambalpur to Bhimpur (Bhimashankar Temple)
- **Optimal**: Sambalpur → Pune → Bhimpur — **₹1150** (Train) ✅
- Sambalpur → Nagpur → Pune → Bhimpur — ₹1300
- Sambalpur → Ujjain → Pune → Bhimpur — ₹1400

### From Sambalpur to Kedarnath Temple
- **Optimal**: Sambalpur → Ambala CNT → Rishikesh → Kedarnath — **₹920** (Train) ✅
- Sambalpur → Ujjain → Haridwar → Rishikesh → Kedarnath — ₹1680
- Sambalpur → Pune → Ambala CNT → Rishikesh → Kedarnath — ₹1800

### From Sambalpur to Ujjain (Mahakaleshwar Temple)
- **Optimal**: Sambalpur → Ujjain — **₹600** (Train) ✅
- Sambalpur → Pune → Ujjain — ₹1350

### From Sambalpur to Haridwar
- **Optimal**: Sambalpur → Ambala CNT → Rishikesh → Haridwar — **₹1020** (Train) ✅
- Sambalpur → Ujjain → Haridwar — ₹1100
- Sambalpur → Surat → Haridwar — ₹1210

---

## 📊 Output Table

| Source      | Destination                    | Optimal Route                                         | Min Cost (₹) |
|-------------|--------------------------------|-------------------------------------------------------|--------------|
| Sambalpur   | Veroval (Somnath Temple)       | Sambalpur → Surat → Veroval                           | 930          |
| Sambalpur   | Bhimpur (Bhimashankar Temple)  | Sambalpur → Pune → Bhimpur                            | 1150         |
| Sambalpur   | Kedarnath                      | Sambalpur → Ambala CNT → Rishikesh → Kedarnath        | 920          |
| Sambalpur   | Ujjain                         | Sambalpur → Ujjain                                    | 600          |
| Sambalpur   | Haridwar                       | Sambalpur → Ambala CNT → Rishikesh → Haridwar         | 1020         |

---

## 📌 Technologies Used
- **Programming Language:** Python / C++ / Java (implementation flexible)
- **Concepts:** Graph Theory, Dijkstra’s Algorithm
- **Data Structures:** Priority Queue, Adjacency List/Matrix

---
<img width="1255" height="707" alt="{A1690FDC-50C2-43AB-B7FF-2BA884E28D99}" src="https://github.com/user-attachments/assets/53f809ad-a2b8-49a8-9c9d-2720638e9173" />


## 🚀 Future Enhancements
- Add **real-time train data** integration.
- Implement **multi-modal transport** options (bus, flight).
- Mobile app interface for **on-the-go planning**.
- Incorporate **time-based optimization** in addition to cost.

---

## 👨‍💻 Contributors 
- Ankit Mohapatra (2202041043)  

---

## 📜 License
This project is open-source and available for academic use.
