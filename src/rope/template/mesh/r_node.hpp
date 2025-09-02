/*
* R_Node
* v 0.0.1
* 2020-2020
* Template R_Node adapted from Rope in the part tab Z_R_Mesh.pde
* https://github.com/StanLepunK/Rope_framework
* 
*/
#ifndef R_NODE_H
#define R_NODE_H
#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "../vec/vec3.hpp"
#include "../../function/rand.hpp" // to generate id  ?


template <class T>
class R_Node : public vec3<T> {
private:
	uint8_t _branch = 2; // minimum to do triangle
	uint64_t _id = 0;
	std::vector<vec3<T>> _links; // in Rope processing it's the dest_list

	vec3<T>_pos;



public:
	R_Node();
	R_Node(T const &arg);
	R_Node(T const &x, T const &y, T const &z);
	R_Node(vec3<T> const &src);
	//  vec3<T> const &from must be a pointer ??????????
	R_Node(vec3<T> const &src, vec3<T> const &from);
	~R_Node();


	// R_Node & set(T const &x, T const &y, T const &z); // from vec3 ?
	// R_Node & x(T const &x); // from vec3 ?
	// R_Node & y(T const &y); // from vec3 ?
	// R_Node & z(T const &z); // from vec3 ?

	uint64_t id(); // get_id() in Rope processing
	uint8_t branch(); // get_branch() in Rope processing
	uint8_t branch_available(); // get_branch_available() in Rope processing
	std::vector<vec3<T>> links(); // vec3 [] get_destination() in Rope processing

	// T x() const; // from vec3 ?
	// T y() const; // from vec3 ?
	// T z() const; // from vec3 ?

};



template <class T>
R_Node<T>::R_Node() : vec3<T>() {
	this->size = 3;
	// this->_id = random_long(UINT_MAX);
	// this->_id = random_long(ULONG_MAX);
	set_list(this->v_list, &this->_x, &this->_y, &this->_z);
	if(R_Node<T>::_warning) {
		std::cout << "Default constructor R_Node" << std::endl;
		R_Node<T>::instance++;
	}	
	return;
}


template <class T>
R_Node<T>::R_Node(T const &arg) : vec3<T>(arg) {
	this->size = 3;
	// this->_id = random_long(UINT_MAX);
	// this->_id = random_long(ULONG_MAX);
	set_list(this->v_list, &this->_x, &this->_y, &this->_z); 
	if(R_Node<T>::_warning) {
		std::cout << "Parametric constructor R_Node" << std::endl;
		R_Node<T>::instance++;
	}
	return;
}

template <class T>
R_Node<T>::R_Node(T const &x, T const &y, T const &z) : vec3<T>(x,y,z) {
	this->size = 3;
	// this->_id = random_long(UINT_MAX);
	// this->_id = random_long(ULONG_MAX);
	set_list(this->v_list, &this->_x, &this->_y, &this->_z); 
	if(R_Node<T>::_warning) {
		std::cout << "Parametric constructor R_Node" << std::endl;
		R_Node<T>::instance++;
	}
	return;
}


template <class T>
R_Node<T>::R_Node(vec3<T> const &src) : vec3<T>(src) {
	this->size = 3;
	// this->_id = random_long(UINT_MAX);
	// this->_id = random_long(ULONG_MAX);
	set_list(this->v_list, &this->_x, &this->_y, &this->_z);
	if(R_Node<T>::_warning) {
		std::cout << "Parametric constructor R_Node" << std::endl;
		R_Node<T>::instance++;
	}	
	return;
}

template <class T>
//  vec3<T> const &from must be a pointer ??????????
R_Node<T>::R_Node(vec3<T> const &src, vec3<T> const &from) : vec3<T>(src) {
	this->size = 3;
	// this->_id = random_long(UINT_MAX);
	// this->_id = random_long(ULONG_MAX);
	set_list(this->v_list, &this->_x, &this->_y, &this->_z);
	if(R_Node<T>::_warning) {
		std::cout << "Parametric constructor R_Node" << std::endl;
		R_Node<T>::instance++;
	}
	_links.push_back(from);

	return;
}


#endif



/**
* R_Node
* v 0.2.0
* 2019-2019
*/
/*
public class R_Node {
	private vec3 pos;
	private ArrayList<vec3> dest_list;
	private int branch = 4;
	private int id;

	public R_Node() {}


	public R_Node(vec3 pos) {
		this.id = (int)random(MAX_INT);
		this.pos = pos;
	}

	public R_Node(vec3 pos, vec3 from) {
		this.id = (int)random(MAX_INT);
		this.pos = pos;
		dest_list = new ArrayList<vec3>();
		dest_list.add(from);
	}

	
	public R_Node copy() {
		R_Node node = new R_Node();
		if(dest_list != null) {
			node.dest_list = new ArrayList<vec3>(dest_list);
		}
		node.pos(this.pos);
		node.set_branch(branch);
		node.set_id(id);
		return node;
	}




	public boolean add_destination(vec3 dst) {
		if(dest_list.size() < branch && !all(equal(pos(),vec3(dst)))) {
			boolean equal_is = false;
			vec3 [] list = get_destination();
			for(int i = 0 ; i < list.length ; i++) {
				if(all(equal(list[i],vec3(dst)))) {
					equal_is = true;
				}
			}
			if(!equal_is) {
				dest_list.add(vec3(dst));
			}
			return !equal_is;
		} else {
			return false;
		}
	}
	
	// set
	public void set_destination(vec3 pos) {
		if(dest_list.size() < branch) {
			dest_list.add(pos);
		} 
	}

	public void set_id(int id) {
		this.id = id;
	}
	
	public void set_branch(int branch) {
		this.branch = branch;
	}

	public void pos(vec3 pos) {
		if(pos == null) {
			this.pos = new vec3();
		}	else {
			this.pos = pos;
		}
	}

	public void x(float x) {
		if(this.pos != null) {
			this.pos.x(x);
		} else {
			this.pos = new vec3(x,0,0);
		}
	}

	public void y(float y) {
		if(this.pos != null) {
			this.pos.y(y);
		} else {
			this.pos = new vec3(0,y,0);
		}
	}

	public void z(float z) {
		if(this.pos != null) {
			this.pos.z(z);
		} else {
			this.pos = new vec3(0,0,z);
		}
	}

	

	// get
	public int get_id() {
		return id;
	}

	public int get_branch() {
		return branch;
	}

	public int get_branch_available() {
		return branch - dest_list.size();
	}

	public vec3 [] get_destination() {
		return dest_list.toArray(new vec3[dest_list.size()]);
	}

	public vec3 pos() {
		return pos.xyz();
	}

	public vec3 pointer() {
		return pos;
	}

	public float x() {
		return pos.x();
	}

	public float y() {
		return pos.y();
	}

	public float z() {
		return pos.z();
	}
}
*/