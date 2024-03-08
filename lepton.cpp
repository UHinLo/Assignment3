#include <iostream>
#include <cmath>
#include <iomanip>
#include "lepton.h"

// Default constructor
lepton::lepton():
  particle_type("Cat"), rest_mass(0), charge(1), check_particle(true), velocity(0), beta(0)
  {
  }

// Parameterized constructor
lepton::lepton(const std::string& type, double mass, bool particle, double v):
  particle_type(type), rest_mass(mass), charge((particle) ? -1 : 1), check_particle(particle), velocity(v), beta(v / light_speed)
  {
    if(abs(beta) > 1)
    {
      velocity = (v > 0) ? light_speed : -light_speed;
      beta = (v > 0) ? 1 : -1;
      std::cout<<"Velocity is higher than speed of light, it will be set to equals to the speed of light"<<std::endl;
    }
  }

// Destructor
lepton::~lepton()
{
  std::cout<<"Destroying lepton: "<<particle_type<<std::endl;
}

// Setters
void lepton::set_particle_type(const std::string& type)
{
  if(type != "electron" && type != "muon")
  {
    std::cout<<"Invalid type of particle. (electron or muon)"<<std::endl;
  }
  particle_type = type;
}
void lepton::set_rest_mass(double mass)
{
  rest_mass = mass;
  std::cout<<"Rest mass of the particle now set to "<<mass<<" MeV"<<std::endl;
}
void lepton::set_check_particle(bool particle)
{
  check_particle = particle;
  charge = (particle) ? -1 : +1;
  std::cout<<"The particle is now a "<<particle_type<<((particle) ? " particle" : " antiparticle")<<" with charge: "<<charge<<std::endl;
}
void lepton::set_charge(int c)
{
  charge = c;
  if(check_particle == true && charge == +1)
  {
    std::cout<<"Charge set does not align with the particle type, particle will be set to it's antiparticle"<<std::endl;
    check_particle = false;
  }
  else if(check_particle == false && charge == -1)
  {
    std::cout<<"Charge set does not align with the particle type, particle will be set to it's particle"<<std::endl;
    check_particle = true;
  }
  else if(check_particle == true && charge == -1)
  {
    std::cout<<"The particle now have charge of "<<charge<<std::endl;
  }
  else if(check_particle == false && charge == 1)
  {
    std::cout<<"The antiparticle now have charge of "<<charge<<std::endl;
  }
  else
  {
    std::cout<<"Charge set does not align with the particle properties"<<std::endl;
  }
}
void lepton::set_velocity(double v)
{
  if(abs(v) > light_speed)
  {
    velocity = (abs(v) <= light_speed) ? v : (v > 0) ? light_speed : -light_speed;
    beta = velocity / light_speed;
    std::cout<<"Velocity is higher than speed of light, it will be set to the speed of light with beta "<<beta<<std::endl;
  }
  else
  {
    velocity = v;
    beta = velocity / light_speed;
    std::cout<<"Velocity is now set to ";
    std::cout<<std::fixed<<std::setprecision(3)<<velocity;
    std::cout<<" m/s with beta as ";
    std::cout<<std::fixed<<std::setprecision(3)<<beta<<std::endl;
  }
}
void lepton::set_beta(double b)
{
  if(b > 1. || b < -1.)
  {
    beta = (b > 0) ? 1 : -1;
    velocity = beta * light_speed;
    std::cout<<"Attempted beta indicating faster than speed of light, it will be set to the beta with speed of light"<<std::endl;
  }
  else
  {
    beta = b;
    velocity = beta * light_speed;
    std::cout<<"Beta is now set to ";
    std::cout<<std::fixed<<std::setprecision(3)<<beta;
    std::cout<<" wtih velocity as ";
    std::cout<<std::fixed<<std::setprecision(3)<<velocity<<std::endl;
  }
}

// Getters
std::string lepton::get_particle_type() const
{
  return particle_type;
}
double lepton::get_rest_mass() const
{
  return rest_mass;
}
bool lepton::get_check_particle() const
{
  return check_particle;
}
double lepton::get_velocity() const
{
  return velocity;
}
double lepton::get_beta() const
{
  return beta;
}
int lepton::get_charge() const
{
  return charge;
}

// Print particle data
void lepton::print_particle_data() const
{
  std::cout<<"-------------"<<std::endl;
  std::cout<<"Particle type: "<<particle_type<<" "<<(check_particle ? "particle" : "antiparticle")<<" | "<<"Rest mass (MeV): "<<rest_mass<<" | "<<"Charge: "<<charge<<" | ";
  std::cout<<std::fixed<<std::setprecision(3)<<"Velocity (m/s): "<<velocity<<" | "<<"Beta (v/c): "<<beta<<std::endl;
  std::cout<<"-------------"<<std::endl;
}
