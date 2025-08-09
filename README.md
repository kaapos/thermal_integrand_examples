# Integrand Evaluation Examples

Examples demonstrating the evaluation of loop integrands at finite temperature and chemical potential

## Dependencies

This project requires the **export branch** of Symbolica:

```bash
pip install git+https://github.com/benruijl/symbolica.git@export
```

## Installation

1. Install the factorint branch of Symbolica (see above)
2. Install other dependencies:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

Run the example:
```bash
python example_symbolica_integrand.py
```

## Project Structure

- `examples/` - Configuration files and integrand definitions
- `integrand.py` - Abstract class for integrands
- `symbolica_integrand.py` - Symbolica implementation of integrands

## Examples

The $n$-loop integrands do not include the normalization factor $1/(2\pi)^{3n}$ but the reported integrated results do include it. Also, integrated counterterms are not included so the results depend on $m_\text{UV}$.

### Two-loop QCD sunset

- Loop-momentum-basis edges: the two fermionic edges
- For the parameter choice $(m_\text{UV}, \mu, \beta) = (2\pi T, \pi T, 1/T)$, the target is $T^4/72\approx 0.0138889\cdot T^4$

### Three-loop QCD Mercedes

- Loop-momentum-basis edges: the three fermionic edges
- For the parameter choice $(m_\text{UV}, \mu, \beta) = (2\pi T, \pi T, 1/T)$, the target is $0.0290399\cdot T^4$